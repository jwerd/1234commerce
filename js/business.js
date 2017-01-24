function Person(name, position)
{
    this.name     = name;
    this.position = position;

    this.getName = function()
    {
        return this.name;
    }
    this.getPosition = function()
    {
        return this.position;
    }
}

function Business(name, staff)
{
    this.name = name;
    // check if we are getting an instance of the Staff Object
    if(!staff instanceof Staff) {
        return;
    }
    this.staff = staff;
    this.hire = function(person)
    {
        console.log(person instanceof Person);
        if(person instanceof Person) {
            this.staff.add(person);
        }
    }
    this.getCompanyName = function()
    {
        return this.name;
    }
    this.getStaffMembers = function()
    {
        return this.staff.getMembers();
    }
}

function Staff(members)
{
    if(!members instanceof Array) {
        return;
    }

    this.members = members;

    this.add = function(person)
    {
        if(!person instanceof Person) {
            return;
        }
        this.members.push(person);

    }
    this.getMembers = function()
    {
        return this.members;
    }
}
// An example of how ot call this and build the objects out:
var owner = new Person('Sean','Owner');
var secondowner = new Person('Jackie','Leecher');
var staff = new Staff([owner,secondowner]);
var scs = new Business('SCS', staff);
var jake = new Person('Jake', 'Tech');
var colby = new Person('Colby', 'Tech');
scs.hire(jake);
scs.hire(colby);
document.writeln("Company report for " + scs.getCompanyName());
document.writeln("=====");
var members = scs.getStaffMembers();
for(var member in members) {
    document.writeln(members[member].getName() + ", with position: " + members[member].getPosition());
}
document.writeln("Yeee, we're at the end...");
