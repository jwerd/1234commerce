<?php

class Person {
    protected $name;
    public function __construct($name)
    {
        $this->name = $name;
    }
}

class Business {
    protected $name;
    protected $staff;

    public function __construct($name, Staff $staff)
    {
        $this->name  = $name;
        $this->staff = $staff;
    }
    public function hire(Person $person)
    {
        $this->staff->add($person);
    }
    public function getCompanyName()
    {
        return $this->name;
    }
    public function getStaffMembers()
    {
        return $this->staff->members();
    }
}

class Staff {
    protected $members = [];
    public function __construct($members = [])
    {
        $this->members = $members;
    }
    public function add(Person $person)
    {
        $this->members[] = $person;
    }
    public function members()
    {
        return $this->members;
    }
}

// An example how to call this and build the objects out:
$owner = new Person('Sean');
$secondowner = new Person('Jackie');
$staff = new Staff([$owner,$secondowner]);
$scs = new Business("SCS", $staff);
$scs->hire(new Person('Jake'));
$scs->hire(new Person('Colby'));

echo "Company report for ".$scs->getCompanyName()."\n";
var_dump($scs);
echo "Yeee, we're at the end...\n";

?>
