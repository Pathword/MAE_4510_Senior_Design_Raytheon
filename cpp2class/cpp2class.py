import os


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

    # getting includes
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

    #get attrs fields, simply grabbing lines between indices
    def get_attrs(self):
        lines = self.lines
        # iterating backwards till first instance include
        for n in range(len(lines) - 1, 0, -1):
            if lines[n].startswith("#include"):
                # end of includes, start of attribute
                attrs_start = n + 1
                break

        # iterating forward till first instance of opening bracket, defines a function
        for n in range(0, len(lines)):
            if lines[n].startswith("{"):
                #end of atts, 2 above first
                attrs_end = n-1
                break

        attrs = lines[attrs_start:attrs_end]
        attrs = [L.split(";")[0] for L in attrs if L != ""]
        attrs = [L.replace("::", " ") for L in attrs]


        #grab just externs
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


        #grab justinits
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

        #concentate
        self.attrs = {**self.inits,**self.externs}



    """
    def get_void_references(self):
        #get ind of each void
        #in each void, check if other init class is referenced, link void to include file and list member includes 
        
        self.void_references = void_references 
    """

    #getting voids and void references
    def get_voids(self):
        #try to looks for voids
        try:
            lines = self.lines
            attrs = self.attrs

            #looks for open brackets, grab descriptor above
            voids = [lines[n-1].split("void ")[1] for n in range(len(lines)) if lines[n].startswith("{")]
            voids_dict = {}


            for void in voids:
                rel = [void.split("::")[0], void.split("::")[1]]
                if rel[0] not in voids_dict.keys():
                    voids_dict.setdefault(rel[0], [rel[1]])
                else:
                    voids_dict[rel[0]].append(rel[1])

            self.voids = voids_dict
            self.parent = False
            #gets void associations, may not be necessary if only grabbing include associations

            #get voids and content of void, analyze void_ind later to get member attributions
            void_ind = {}
            for n in range(len(lines)):
                if lines[n].startswith("{"):
                    for c in range(n, len(lines)):
                        if lines[c].startswith("}"):
                            member = lines[n-1].split("void ")[1]
                            void_ind.setdefault(member,lines[n: c+1])
                            n = c
                            break

            self.void_ind = void_ind


            includes = [inc.replace(".h", "") for inc in self.includes]

            include_vars = {}
            for var in list(attrs.keys()):
                if attrs[var] in includes:
                    include_vars.setdefault(var,attrs[var])

            self.include_vars = include_vars
            void_assoc = {}
            #look at all voids
            for void in list(void_ind.keys()):
                #decalre void lines
                void_lines = void_ind[void]
                #declare list of associations
                assoc = []
                #for each line in void_lines
                for L in void_lines:
                    #for each include
                    for inc in list(include_vars.keys()):
                        #if inc found in L
                        if inc in L:
                            #check for doubles
                            if include_vars[inc] not in assoc:
                                assoc.append(include_vars[inc])

                        void_assoc.setdefault(void,assoc)


            self.void_assoc = void_assoc



        #try to looks for int main
        except:
            for n in range(len(lines)):
                if "int main()" in lines[n]:
                    self.voids = {"main":"int main()"}
                    self.parent = True
        """
        #if found voids, get void references 
        if self.voids:
            self.get_void_references(self.void)
        """




    #get all
    def get(self):

        try:
            self.get_includes()
        except:
            self.includes = "ERROR: could not get includes "
        try:
            self.get_attrs()
        except:
            self.attrs = "ERROR: could not concatenate initialized and external variables"
        try:
            self.get_voids()
        except:
            self.voids = "ERROR: could not get voids"

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


    def get_class(self):
        lines = self.lines
        myclass = [L.split("class ")[1] for L in lines if L.startswith("class ")][0]
        class_dict = {}

        #get indicies of class info
        for n in range(len(lines)):
            if lines[n].startswith("{"):
                for c in range(n,len(lines)):
                    if lines[c].startswith("}"):
                        ind = [n,c+1]
                        break

        #get class lines and clean tabs
        class_lines = [L.replace("\t","").split(";")[0] for L in lines[ind[0]:ind[1]]]
        class_voids = [L.split("void ")[1].replace("()","") for L in class_lines if "void " in L]


        #get modifier
        for L in class_lines:
            if "public" in L:
                modifier = "public"
                break
            elif "private" in L:
                modifier = "private"
                break
            else:
                modifier = "unknown"

        #get indices of start of void, end of modifier:
        attr_ind = []
        for n in range(len(class_lines)-1,0,-1):
            if class_lines[n].startswith("public") or class_lines[n].startswith("private"):
                attr_ind.append(n+1)

        for n in range(len(class_lines)):
            if class_lines[n].startswith("void"):
                attr_ind.append(n)
                break

        attrs = {}
        for n in range(attr_ind[0],attr_ind[1]):
            type = class_lines[n].split(" ")[0]
            value = "".join(class_lines[n].split(" ")[1:])
            attrs.setdefault(value,type)

        self.modifier = modifier
        self.attrs = attrs
        self.class_lines = class_lines
        self.voids = class_voids


    def get(self):
        try:
            self.get_class()
        except:
            self.modifier = "error"
            self.attrs = "error"
            self.attr_ind = "error"
            self.ind = "error"
            self.class_lines = "error"
            self.voids = "error"

        try:
            self.get_includes()
        except:
            self.includes = "error"



def cpp2class(path):
    #init obj called cpp
    cpp = cpp_file(path)
    #perform get
    cpp.get()

    return cpp


def h2class(path):
    #init obj called h
    h = h_file(path)
    #perform get
    h.get()

    return h


"""
simply grab path, locate h and cpp files and read 
"""
#path of directory to analyze specified using GUI/explorer editor
path = "C:\\Users\\Dylan\\Documents\\School\\UCCS\\Classes\\2019\\Fall 2019\\MAE 4510\\Github\\MAE_4510_Senior_Design_Raytheon\\ConsoleApplication1\\ConsoleApplication1"

#set cwd
os.chdir(path)
#get files
files = os.listdir(path)

#get h and cpp files
h_files = [f for f in files if f[-2:] == ".h"]
cpp_files = [f for f in files if f[-4:] == ".cpp"]

"""
#get classes from h files
h_classes = {}
for file in h_files:
    h_classes.setdefault(file,h2class(path+"\\"+file))
"""

#get classes from cpp files
cpp_classes = {}
for file in cpp_files:
    cpp_classes.setdefault(file,cpp2class(path+"\\"+file))

#get classes from h files
h_classes = {}
for file in h_files:
    h_classes.setdefault(file,h2class(path+"\\"+file))
