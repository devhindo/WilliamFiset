#!/bin/bash
# Download slides for each playlist


pdf() {
    local name="$1"
    local link="$2"

    if [ -f "$name/$name.pdf" ]; then
        echo "$name.pdf exists"
    else
        wget "$link"
        mv *.pdf "$name/$name.pdf"
    fi
}

# Tree Algorithms

pdf "tree" "https://raw.githubusercontent.com/williamfiset/Algorithms/master/slides/graphtheory/tree_algorithm_slides.pdf"
