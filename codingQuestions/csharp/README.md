# CSharp

I'm still a beginner to this, so I'm trying to understand CLI build and run
processes from a Linux perspective instead of using external build tools within
VSCode or otherwise.

>~[TODO]: fill out remaining instructions

## Building
on linux, would need either mono or dotenv sdk.

dotnet-sdk requires all the boilerplate and support files
in order to just build the files in CSharp, which I think is stupid.
See the ``Publish.proj`` file for an example...

using dotnet-sdk:
```
dotnet build Publish.proj
```

mono is much easier. Just mcs for compile and mono for runtime. 

```
mono [File to build]
```
