# reason-helpers


[![CircleCI](https://circleci.com/gh/yourgithubhandle/reason-helpers/tree/master.svg?style=svg)](https://circleci.com/gh/yourgithubhandle/reason-helpers/tree/master)


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

## Developing:

```
npm install -g esy
git clone <this-repo>
esy install
esy build
```

## Running Binary:

After building the project, you can run the main binary that is produced.

```
esy x ReasonHelpersApp.exe 
```

## Running Tests:

```
# Runs the "test" command in `package.json`.
esy test
```
