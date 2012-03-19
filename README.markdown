
What is Lua Safe?
-----------------

Lua Safe is a patch to add tainted variables and safety levels to Lua.  It is
similar to and uses ideas from Perl and Ruby.  It was implemented as a
class project at the [Rochester Institute of Technology](http://www.rit.edu).   The
code was written by Zachary P. Landau.  The research was done by Charles
Lee, Heidi Morales, Ray Wallace, and Sam Won.

Using Lua Safe
--------------

Lua Safe support adds the following functions: setsafelevel(num),
getsafelevel(), taint(var), untaint(), and istainted(var).  To set the taint
level, either call setsafelevel() with the desired safety level, or use the -T
command line parameter.  Once this is done, safety levels will be in effect.

To run the Lua Safe version of the interpreter, run 'bin/lua'.  Without
parameters, it will give you a Lua prompt.  If you include a filename, it will
run that file as a script.  To run the unit tests, which also show off the
different functionality, go into the safe/ directory and type 'make'.  This
will run all of the unit tests.  For example usage, see the files in
safe/examples.

Date: 2005-06-02
