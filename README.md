# container

## Description

A WIP Tool to manage loads/unloads of containers from ships.

### Rules of sorting container on loads

- You can stack a container on another one **if** the destination of the container is before or the same as the one below it.  

## Usage

### Build

```bash
$ make
```
### Input file
The input file must be in the following format:

 * 1st line: number of destinations (ports) the ship will visit
 * 2nd line: ID of the ports the ship will visit separated by ; (semicolon)
 * 3rd line: number of containers
 * The next lines are the containers, each line is a container, in the following format:
    * ID;From;Dest

#### Exemple

From [test file](test.txt)
```text
5;4;2           // size of the ship length;width;max_height
3               // number of ports
321;333;185;    // ports
5               // number of containers
17;321;322      // containers ID;From;Dest
123;322;333
21;321;185
23;322;185
43;321;333
```

## TODO / Roadmap

- [x] Read a list of containers from a file and manage which containers are loaded/unloaded from which ports
- [ ] Output a list of files for all ports with the containers to be loaded/unloaded (basic thing "get"/"put")
- [ ] Maybe a GUI?