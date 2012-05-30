#!/bin/bash

// Remove error defines in moc_* files
// Qt version 4.8 produces errors which can be fixed with this workaround
// Not the best solution but it works for version 4.8

sed -i '13,16 s/^/\/\//' moc*.cpp
