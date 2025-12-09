# Notes about Language Specs

I found [phplang.org](https://phplang.org), which looks like a facebook documentation
for the PHP language.

I'm going to take notes about PHP here so I can use them later.

"VSlot", "VStore", "HStore"

VSlot -> variable: (local var, array element, instance property, static property)
VStore -> "Program value", scalar or handle pointing to heap store.
    Scalar types: Bool, int, float, string, null
HStore -> Heap store for "composite values", which contains "zero or more vslots"
        and other information related to object/array attributes
    Composite types: array, object.

"By reference" is done with &. normal variables just do direct vslot-vstore relations,
    but a vslot can point to a vstore with &, then the old vstore is deleted

PHP is garbage-collected as an interpreter


