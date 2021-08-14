# Spike Survival

Simple C++ console game. 

## About the game

You have to survive as long as possible. There's a map (currently 20x20 but will be custom in the future) where you can move where and how you want. Each move you make a new spike will be spawned randomly on the map. At first, the game is easy and you can move everywhere, but after a while the whole map will be filled with spikes. How many points can you get?

## Features

* Responsive and fast console game.
* Everything is random, you won't have the same game twice.

## Compiling

You need to have *cmake* and *make* installed in order to compile it.
After that, create a new **build/** directory, go into it and type:

```bash
cmake ../
make
```

## Running

Run the executable file created.

```bash
.\spikesurvival.exe
```