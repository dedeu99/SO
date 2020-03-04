#!/bin/bash
[[ ! $# -eq 1 ]] && { echo "usage:$0 \"termo pesquisa\"" ; exit 0; }
ls | ( grep "$1" )
