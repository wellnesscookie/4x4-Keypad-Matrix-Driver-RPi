# KeyPad-4x4-Matrix driver for RPi

## Building & Compiling & Inserting

### Driver
```
$ make
$ mknod -m 666 /dev/gpio_driver c <major_number> <minor_number>
```
To retrieve major and minor number, you can use `$ cat /proc/devices` command to find appropriate values for your environment and module.

### Test example

Reading directly from nod file
```
$ cat /dev/gpio_driver
```

### Driver visualisator
```
$ cd ./test_driver_visualisator
$ gcc keyboardVisualisator.c -o vis
$ ./vis
```

### Driver game
```
$ cd ./test_driver_game
$ gcc main.c keypadMatrix.c board.c sprite.c -o game
$ ./game
```

### Wiring RPi with 4x4 Keypad Matrix

Connect GPIO pins with Keypad Matrix in reference to:
<table>
<tr><td>

| GPIO Pin | Keypad Matrix Pin |
|----------|-------------------|
| 10       | C0                |
| 22       | C1                |
| 27       | C2                |
| 17       | C3                |

</td><td>

| GPIO Pin | Keypad Matrix Pin |
|----------|-------------------|
| 18       | R0                |
| 23       | R1                |
| 24       | R2                |
| 25       | R3                |

</td></tr> </table>

### Demonstration

Youtube video: https://youtu.be/xZTHvI5SSF8
