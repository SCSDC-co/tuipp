#!/usr/bin/env bash

set -eo pipefail

cd "$(dirname "$0")" || exit 1

[ ! -d ../build ] && mkdir ../build

cd ../build || exit 1

cmake .. -DTUIPP_BUILD_DOCS=ON || {
    echo "cmake failed"
    exit 1
}

cmake --build . || {
    echo "ninja failed"
    exit 1
}
