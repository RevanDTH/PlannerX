# PlannerX

A lightweight, console based task planner for Windows, MacOS (Soon) and Linux (Soon).

## Table of Contents

- [About](#about)  
- [Features](#features)  
- [Quick Start](#quick-start)  
    - [Prerequisites](#prerequisites)  
    - [Installation](#installation)  
- [Configuration](#configuration)  
- [Using](#using)  
- [Known Bugs]()
- [Contributing](#contributing)   
- [License](#license)  
- [Contact](#contact)

## About

PlannerX is a small and lightweight task planner that you can use on your daily basis. It is designed to be used in a terminal, so that you don't have to exit your terminal to write down some tasks you want to do later. PlannerX is a very small project that I'm trying to build in my free time in order to boost my C++ skills. My code probably has some mistakes and weird code chunks, if you seem them, feel free to fork my repo and fix my code. I will try my best to read trough your push requests and try to learn something :) 

## Features

- Terminal based  - The whole application is terminal based, so no need for you to exit your beloved terminal to create a todo for later :)   
- Cross platform - I will try to write my code platform-independent, at the moment all the development is done on a windows machine.
- More features to come

## Quick Start

### Prerequisites
There are no prequisites if you download the latest build from github. If you want to build your own version of PlannerX then you will probably need this: 

- C++ compiler (obviously)


### Installation

If you want to build the tool yourself and therefore need the source-code, just do the following:
```bash
# clone repository
git clone https://github.com/RevanDTH/PlannerX.git
cd PlannerX
```

### Using

The first time you use PlannerX, it is recommended to start it with the -setup parameter so that PlannerX can install itself correctly! You are able to use PlannerX without running the -setup parameter but then the savefile will be created in the same directory where the executable is located. Here is how you start PlannerX with the setup parameter: 

```bash
plannerx -setup
```

### Known Bugs

There are some known bugs in in PlannerX. This following list shows all the Bugs that are known and also have a corresponding issue already opened, so please don't open another Issue if you encounter this bug. 

| Bug | Issue |
|-----|-------|
|  Program crashing when entering non-integer values to the main menu   |    [Issue](https://github.com/RevanDTH/PlannerX/issues/1)   |

## Contributing

Guidelines for contributors:

- Fork the repo and create a feature branch  
- Provide a clear PR description and link to related issue

## License

This whole project is licensed under the GNU General Public License v3.0


## Contact

Maybe I will create a Kanban board if I extend this project but at the moment it doesn't seem like the project is big enough to add anykind of progress board. 
