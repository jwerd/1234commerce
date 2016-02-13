class Person:
    _name     = None
    _position = None

    def __init__(self, _name, _position):
        self.name = _name
        self.position = _position

class Business:
    def __init__(self, name, staff):
        self.name = name
        self.staff = staff
    def hire(self, person):
        self.staff.add(person)
    def getStaffMembers(self):
        return self.staff.list()
    def getCompanyName(self):
        return self.name

class Staff:
    _members = None
    def __init__(self, members):
        self._members = members;
    def add(self, person):
        self._members.append(person)
    def list(self):
        return self._members

# An example how to call this and build the objects out:
owner = Person('Sean','Owner')
secondowner = Person('Jackie','Leecher')
staff = Staff([owner,secondowner]);
scs = Business('SCS', staff)
owner._name = 'Digi' #not possible now :)
jake = Person('Jake', 'Tech')
colby = Person('Colby', 'Tech')
scs.hire(jake)
scs.hire(colby)

print "Company report for " + scs.getCompanyName()
print "====="
for member in scs.getStaffMembers():
    print member.name + ", with position: " + member.position;
print "Yeee, we're at the end..."
