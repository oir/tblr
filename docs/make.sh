#! /bin/bash

# run from the top directory
doxygen docs/Doxyfile && \
doxybook2 -i xml -o docs/api --config docs/config.json --templates docs/tmpl/ && \
rm -rf xml
