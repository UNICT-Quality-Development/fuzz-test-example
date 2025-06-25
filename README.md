```bash
mkdir build
cd build
cmake .. -DCMAKE_CXX_COMPILER=clang++
cmake --build . -- -j$(nproc)
```

```
timeout 30 ./fuzz_math_utils || echo "Fuzz test crashed or timed out"
```

```
hexdump -v -e '"%d, "' -e '8/1 "0x%02x, " "\n"' ./crash-1bf826e4edde83deb4ed397785f6fb3c0148ed7f
```

```
xxd crash-...
```

```
gdb ./fuzz_math_utils
run < ./crash-09aec12df66a8e188dbcd0f2cc608d9aca423080
```
