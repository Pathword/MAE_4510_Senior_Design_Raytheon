

class members:
    def __init__(self,k):
        self.k = k

    def addsubclass(self,value):
        self.n = value

class a:
    def __init__(self,path):
        self.path = path

    def addsubclass(self,value):
        self.members = members(value)
