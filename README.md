# Brainfuck

A brainfuck interpreter written in C

## Build
```bash
$ make
```

## Run

```bash
$ ./brainfuck tests_programs/hello_world.bf #or any other .bf
```

## Demo

```shell
$ ./brainfuck tests_programs/54321.bf
543210

$ ./brainfuck tests_programs/hello_world.bf
Hello World

$ ./brainfuck tests_programs/print_input.bf
Hi!
Hi!

$ ./brainfuck tests_programs/print_with_loop.bf
copy@copy.sh%
```

## Test

Run tests with [jenrik](https://github.com/Yohannfra/JenRik)

```
$ jenrik test_brainfuck.toml
```
