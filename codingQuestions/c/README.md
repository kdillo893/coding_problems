# C coding things

## PreReqs
I changed things to use autotools for the build process for no good reason. It 
still uses manually entered targets for sources to compile, but whatever!

### autotools setup
first in the base directory, run
```
aclocal
```

then
```
autoconf
```
. Ignore the warning. Then
```
autoheader
```
Then
```
automake -a
```

The -a is needed to add some configure files and scripts that are missing.
That should give you a working configure script. Go ahead and run
```
./configure
```

This will give you a working makefile

## Building
If you want to avoid my bad autotools usage, just do this:

```
make -f Makefile_NoAuto
```

trying out some autoconfig and automake stuff. This is probably stupid, but whatever.

After the autotools prereq, you can now just run
```
make
```

## Running
Just do the following

```
./leetcode
```

## Cleanup

```
make clean
```

if you want to remove some of the "building autotools" garbage, run
```
make distclean
```

this will require you to run the configure script again before make.
