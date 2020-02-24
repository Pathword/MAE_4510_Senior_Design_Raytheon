
class cpp_file:
    #initialize object
    def __init__(self,path):
        self.path = path

        #opens and closes file on path
        #split into lists, index is line
        file = open(path,"r")
        lines = file.read().split("\n")
        file.close()
        #get rid of blank lines
        self.lines = [L for L in lines if L != ""]

    #getting includes
    def get_includes(self):
        lines = self.lines
        incs = []
        # getting incs
        incs = [L.split("#include ")[-1] for L in lines if L.startswith("#include")]



        clean_inc = []
        # cleaning
        for inc in incs:
            """
            removes = ["\"", ".h", "<", ">"]
            """
            removes = ["\""]
            for r in removes:
                inc = inc.replace(r, "")

            clean_inc.append(inc)

        self.includes = clean_inc


    #getting voids
    def get_voids(self):
        lines = self.lines
        voids = [L.split("void ")[1] for L in lines if L.startswith("void")]
        voids_dict = {}

        for void in voids:
            rel = [void.split("::")[0], void.split("::")[1].replace("()", "")]
            if rel[0] not in voids_dict.keys():
                voids_dict.setdefault(rel[0], [rel[1]])
            else:
                voids_dict[rel[0]].append(rel[1])

        self.voids = voids_dict

    #get attrs fields, simply grabbing lines between indices
    def get_attrs(self):
        lines = self.lines
        # iterating backwards till first instance include
        for n in range(len(lines) - 1, 0, -1):
            if lines[n].startswith("#include"):
                # end of includes, start of attribute
                attrs_start = n + 1
                break

        # iterating forward till first instance of void
        for n in range(0, len(lines)):
            if lines[n].startswith("void"):
                # end of attrs, start of void loop
                attrs_end = n
                break

        attrs = lines[attrs_start:attrs_end]
        attrs = [L.split(";")[0] for L in attrs if L != ""]
        attrs = [L.replace("::", " ") for L in attrs]

        return attrs

    #getting external variables
    def get_externs(self):
        #grabbing attrs
        attrs = self.get_attrs()
        externs_dict = {}
        # get externs
        externs = [L.split("extern ")[-1] for L in attrs if L.startswith("extern")]
        for ext_var in externs:
            rel = [ext_var.split(" ")[0], ext_var.split(" ")[1]]

            if rel[0] not in externs_dict.keys():
                # key is type, value is list of instances
                externs_dict.setdefault(rel[1], rel[0])
            else:
                print("error: found extra extern")

        self.externs = externs_dict

    #getting initialized variables
    def get_inits(self):
        attrs = self.get_attrs()
        inits_dict = {}
        # get initialized vars
        inits = [L for L in attrs if L.startswith("extern") == False]
        for inits_var in inits:
            rel = [inits_var.split(" ")[0], inits_var.split(" ")[1]]

            if rel[0] not in inits_dict.keys():
                inits_dict.setdefault(rel[1], rel[0])
            else:
                print("error: found extra init")

        self.inits = inits_dict


"""
get attributes by init, extern, and void members 
"""
class h_file:
    def __init__(self,path):
        self.path = path
        #opens and closes file on path
        #split into lists, index is line
        file = open(path,"r")
        lines = file.read().split("\n")
        file.close()
        #get rid of blank lines
        self.lines = [L for L in lines if L != ""]




def cpp2class(path):
    game_cpp = cpp_file(path)
    game_cpp.get_voids()
    game_cpp.get_includes()
    game_cpp.get_externs()
    game_cpp.get_inits()

    print(game_cpp.voids)
    print(game_cpp.includes)
    print(game_cpp.externs)
    print(game_cpp.inits)

    return game_cpp


#pass filename and lines

path1 = "C:\\Users\\dcopley\\Desktop\\Python Stuff\\test\\game_cpp.txt"
path2 = "C:\\Users\\dcopley\\Desktop\\Python Stuff\\test\\boss_cpp.txt"
path3 = "C:\\Users\\dcopley\\Desktop\\Python Stuff\\test\\bossmonsters_cpp.txt"
path4 = "C:\\Users\\dcopley\\Desktop\\Python Stuff\\test\\invent_cpp.txt"
path5 = "C:\\Users\\dcopley\\Desktop\\Python Stuff\\test\\monster_cpp.txt"

paths = [path1,path2,path3,path4,path5]

all_classes = {}

for path in paths:
    myclass = cpp2class(path)

    all_classes.setdefault(path,myclass)

