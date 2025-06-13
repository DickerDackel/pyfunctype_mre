# Update

Solution was given on pydis.

`PyCFunction_New` with the record that was used to add the function to the
module.

Here's the initial question:

# How do I get a PyFunction object from a C-function?

I have created a module with a bunch of functions, and also want to provide a
lookup table (dict) with specific tasks that point to the appropriate
function.

I can create that dict with `PyModule_AddObject`.  The dict parsing and
constructing works too.  And when I let the dict entry point e.g. to a string
object, everything is constructed properly.  But if replace that with the C
function, that segfauls (not suprising).

For most types, there's the `PySOMETYPE_FROM_C_TYPE`, but I can't find that
for `PyFunction`.  So how can I get a `PyFunction` object from my C-function?

Here's an MRE.  Building and importing that segfauls.  Commenting out the
`this_segfaults` part all at the bottom, it works as expected.  So what Do I
have to wrap around `mre_zefunction` in `Py_BuildValue`?
