class Dir(object):
    def __init__(self):
        self.dirs = collections.defaultdict(Dir)
        self.files = {}

class FileSystem(object):

    def __init__(self):
        self.root = Dir()

    def ls(self, path):
        """
        :type path: str
        :rtype: List[str]
        """
        dirs = path.split("/")
        # print(self.root.dirs.keys())
        # print(dirs)
        curr = self.root
        for dir in dirs:
            if dir and dir in curr.dirs:
                # print(dir)
                curr = curr.dirs[dir]
        if dirs[-1] in curr.files:
            return [dirs[-1]]
        else:
            return sorted(curr.dirs.keys() + curr.files.keys())

    def mkdir(self, path):
        """
        :type path: str
        :rtype: None
        """
        dirs = path.split("/")
        # print(dirs)
        curr = self.root
        for dir in dirs:
            if dir:
                curr = curr.dirs[dir]
                

    def addContentToFile(self, filePath, content):
        """
        :type filePath: str
        :type content: str
        :rtype: None
        """        
        dirs = filePath.split("/")
        curr =self.root
        for dir in dirs[:-1]:
            if dir:
                curr = curr.dirs[dir]
        if dirs[-1] in curr.files:
            curr.files[dirs[-1]] += content
        else:
            curr.files[dirs[-1]] = content


        

    def readContentFromFile(self, filePath):
        """
        :type filePath: str
        :rtype: str
        """
        dirs = filePath.split("/")
        curr =self.root
        for dir in dirs[:-1]:
            if dir:
                curr = curr.dirs[dir]
        return curr.files[dirs[-1]]



# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)
