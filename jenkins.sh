podman build -t fallow_engine .
podman run -mount


docker run \
  --name fallow_builder \
  --mount type=bind,source=$(WORKSPACE_DIR)/,target=/Ansa \
  /bin/bash /docker_builder.sh
