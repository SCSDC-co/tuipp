#!/usr/bin/env bash

set -eo pipefail

cd "$(dirname "$0")" || exit 1

[ ! -d ../build ] && mkdir ../build

cd ../build || exit 1

cmake .. --preset default -DTUIPP_BUILD_DOCS=True || {
    echo "cmake failed"
    exit 1
}

ninja || {
    echo "ninja failed"
    exit 1
}
