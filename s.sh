#!/bin/bash
P=/home/grid/testbed.univ.kiev.ua/tb385/lab4/;
N=2000;
M=4000;
G="$P"g.out
S="$P"s.out
$G 1 $N $M
$S > "$P"out1.txt
$G 2 $N $M
$S > "$P"out2.txt
$G 4 $N $M
$S > "$P"out4.txt
$G 8 $N $M
$S > "$P"out8.txt