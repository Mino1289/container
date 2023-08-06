# container

## Description

A WIP Tool to manage loads/unloads of containers from ships.

## Usage
The input file must be in the following format:

 * 1st line: number of destinations (ports) the ship will visit
 * 2nd line: ID of the ports the ship will visit separated by ; (semicolon)
 * 3rd line: number of containers
 * The next lines are the containers, each line is a container, in the following format:
    * ID;From;Dest

## TODO / Roadmap

- [ ] Read a list of containers from a file and manage which containers are loaded/unloaded from which ports
- [ ] Output a list of files for all ports with the containers to be loaded/unloaded (basic thing "get"/"put")
- [ ] Maybe a GUI?