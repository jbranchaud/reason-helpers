# ReasonML Helpers

> A collection of helper functions that have proved useful as I've explored ReasonML

You can view all the helpers in the [Util.re](https://github.com/jbranchaud/reason-helpers/blob/master/library/Util.re) file.

## Pesy Documentation

> This project was bootstrapped by and is powered by [Pesy](https://github.com/jordwalke/pesy). The following documentation explains how to work with the Pesy part of this project.

**Contains the following libraries and executables:**

```
reason-helpers@0.0.0
│
├─test/
│   name:    TestReasonHelpers.exe
│   main:    TestReasonHelpers
│   require: reason-helpers.lib
│
├─library/
│   library name: reason-helpers.lib
│   namespace:    ReasonHelpers
│   require:
│
└─executable/
    name:    ReasonHelpersApp.exe
    main:    ReasonHelpersApp
    require: reason-helpers.lib
```

### Developing:

```
npm install -g esy
git clone <this-repo>
esy install
esy build
```

### Running Binary:

After building the project, you can run the main binary that is produced.

```
esy x ReasonHelpersApp.exe 
```

### Running Tests:

```
# Runs the "test" command in `package.json`.
esy test
```
