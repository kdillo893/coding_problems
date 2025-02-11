## Compiling with CLI

I keep getting annoyed with needing to refer to documentation, so I'm making notes
so I don't need to keep going back

Options to keep in mind:
* ``-d [directory]`` -> destination directory for class files
* ``-s [directory]`` -> destination for generated source files
* ``-cp [classpath]`` -> specify the classpath for includes and preprocessors
* ``-g`` -> generate debug information 
* ``-source [#number]`` -> specify java SE compilation target (15, 17, 21, etc)

### Just one file?
```
javac /path/to/java/file
```

### A file that includes small amounts of other files?
```
javac /path/to/main/java/file /path/to/file1 /path/to/file2 ...
```

### A file that includes many files?

First create a file that keeps track of sources, like the following from a baeldung article:
```
find ./src/ -type f -name "*.java" > sources.txt
```
find is unix way of searching for files/directories relative to current directory.
``-type f`` means to look for files, and we redirect output to a file ``sources.txt``

once we have the sources listed, we can do the following:

```
javac -d /path/to/build/dir @sources.txt
```

## Running with CLI

Something to keep in mind when running packages in CLI:
* do i need to link other libraries at runtime? If so, include in classpath
* just like PATH variables in other OS aspects, you can include different
directories by separating folders with ``:``. EG below:
```
java -cp /home/kdill/onepath:/home/kdill/somelib:/home/kdill/otherlib ProgramName
```
* Note when refering to classes for the java runtime, no need to use extensions
* To make shipping overall code easier and not deal with configuration files,
you can just package all the required files into a .jar and run them from jars later


### Just one class for the program?
```
java [package.path.]ProgramName
```

### One Program which references other classes?
```
java -cp /target/classes [package.path.]ProgramName
```
