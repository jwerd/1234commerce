/**
 * business
**/


#include <stdio.h>
#include <string.h>


#define YAH_HIRED_KID        b->staffcnt++;
#define set_owner(b, x, y)   staff_add(b, x, y, OWNER)
#define hire(b, x, y)        staff_add(b, x, y, HIRED)
#define fire(b, x)           staff_mod(b, x,    FIRED)


#define HIRED     0x00
#define FIRED     0x01
#define LEECHER   0x40
#define OWNER     0x80


typedef struct {
    char *name;
    char *position;
    unsigned char flags;
} Staff;

typedef struct {
    char *name;
    char staffcnt;
    Staff *staff;
} Business;


/* staff management */
static Staff * staff_add(Business *b, char *name, char *position, char flags)
{
    // sanity check
    if (b->staff == 0) return 0;

    // add staff
    Staff *new;
    new = &b->staff[b->staffcnt];

    new->name     = name;
    new->position = position;
    new->flags    = flags;

    YAH_HIRED_KID

    return new;
}

static char staff_find(Business *b, char *name)
{
    int i;

    for (i = 0; i < b->staffcnt; i++) {
        if (!strcmp(name, b->staff[i].name)) {
                return i;
        }
    }

    return -1;
}

static void staff_mod(Business *b, char *name, char flags)
{
    char idx;

    idx = staff_find(b, name);
    if (idx > 0) {
        b->staff[idx].flags = flags;
    }
}


/* tps reports */
static void print_employee_report(Business *business)
{
    int i;
    Staff *member;

    for (i = 0; i < business->staffcnt; i++) {
        member = &business->staff[i];
        if ((member->flags & FIRED) != FIRED) {
                printf("%s, with position: %s\n", member->name, member->position);
        }
    }
}


/* new beginnings */
void main()
{
    Business scs;       // our business aint GLOBAH
    Staff    staff[32]; // we'll never hire this many people

    // yeee
    scs.name  = "SCS";
    scs.staff = staff;

    // owners
    set_owner(&scs, "Sean", "Owner");
    set_owner(&scs, "Jackie", "Leecher");
    staff_mod(&scs, "Jackie", OWNER | LEECHER);

    // side business
    Business ibkomputahs;
    ibkomputahs.staff = &staff[9];  // steals from main business
    set_owner(&ibkomputahs, "Lisa", "CFO (Chief Foodmow Omnoms)");

    // employees
    hire(&scs, "Jake", "Tech");
    hire(&scs, "Colby", "Tech");
    hire(&scs, "Cameron", "Tech");
    hire(&scs, "Marty Wall", "Tech");

	// wait a minute
    fire(&scs, "Cameron");
    fire(&scs, "Marty Wall");

    // show our report
    printf("Company report for %s\n=====\n", scs.name);
    print_employee_report(&scs);

    // we done yeeee
    printf("Yeee, we're at da end...\n");
}
