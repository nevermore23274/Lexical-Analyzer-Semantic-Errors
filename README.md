# Lexical-Analyzer-Semantic-Errors

# General Usage
- From the root directory you'll run:
```
docker build -t sem-errors:latest -f docker/Dockerfile .
```
- Then you'll run:
```
docker run --name sem-errors -v <location_to_root_folder>:/sem-errors -it sem-errors
```
- Once inside container and ready to test:
```
./compile < <filename>.txt
```
