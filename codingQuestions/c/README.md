# C coding things


## Building
If you want to avoid my bad autotools usage, just do this:
```
make -f Makefile_NoAuto
```

### Autotools build process
> [!WARNING]
> I believe autotools building is broken, but try just in case

Run the following in sequence:
```
autoconf
```

```
automake
```

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

## Autotools alternative:
I tried to make things work with autotools, which is why there are a bunch of files 
related to that. I'll try to figure that out again sometime.
