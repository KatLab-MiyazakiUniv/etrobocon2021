#!/bin/bash

ETROBO_ROOT="${HOME}/etrobo"

# download package
if [ -d "$ETROBO_ROOT" ]; then
    "$ETROBO_ROOT/scripts/etrobopkg"
fi

# install Athrill2 & UnityETroboSim
"$ETROBO_ROOT/scripts/setup.sh"

# invoke etrobo environment
cd "$ETROBO_ROOT"

ln -s /tmp/etrobocon2021 $ETROBO_ROOT/workspace/etrobocon2021

if [ -z "$ETROBO_ENV" ]; then
    . "$ETROBO_ROOT/scripts/etroboenv.sh" silent
fi

make app=etrobocon2021
