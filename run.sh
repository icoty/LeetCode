#!/bin/bash
ps -ef | grep "readme" | head -n 2 | awk '{print $2}' | xargs kill -9
#rm solution/*
python3 readme.py
