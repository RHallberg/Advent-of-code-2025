#!/bin/sh
tac $1 | awk -f solution.awk
