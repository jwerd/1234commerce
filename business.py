class Person:
    name     = None
    position = None

    def __init__(self, name, position):
        self.name = name
        self.position = position

class Business:
    def __init__(self, name, staff):
        self.name = name
        self.staff = staff
    def hire(self, person):
        self.staff.add(person)
    def getCompanyName(self):
        return self.name

class Staff:
    members = []
    def __init__(self):
        pass
    def add(self, person):
        self.members.append(person)

# An example how to call this and build the objects out:
owner = Person('Sean','Owner')
secondowner = Person('Jackie','Leecher')
staff = Staff()
scs = Business('SCS', staff)
scs.hire(owner)
scs.hire(secondowner)
jake = Person('Jake', 'Tech')
colby = Person('Colby', 'Tech')
scs.hire(jake)
scs.hire(colby)
print "Company report for " + scs.getCompanyName()
print "====="
for member in staff.members:
    print member.name + ", with position: " + member.position;
print "Yeee, we're at the end..."
