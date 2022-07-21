SCRIPT_DIR="$( cd -- "$( dirname -- "${BASH_SOURCE[0]:-$0}"; )" &> /dev/null && pwd 2> /dev/null; )";

podman build -t fallow_builder ${SCRIPT_DIR} 

podman run \
  --mount type=bind,source=${WORKSPACE_DIR}/,target=/Ansa \
  fallow_builder \
  /bin/bash /docker_build.sh
