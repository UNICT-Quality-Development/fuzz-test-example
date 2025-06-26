## Fuzz test example

This repository contains the source code for a fuzz testing example.

It was created specifically for a presentation at the University of Catania, and is accompanied by slides used during the event.

- 📍 [Event](https://web.dmi.unict.it/it/corsi/l-31/secure-systems-and-programmable-networks-tools-future)
- 📄 [Slides](docs/)
- ▶️ [Teams Event + Video](https://teams.microsoft.com/l/meetup-join/19%3ameeting_OWI2ZmZmMmYtZmRjMS00NDE3LTliNWEtZGRlMDRjODU4Mzky%40thread.v2/0?context=%7b%22Tid%22%3a%22baeefbc8-3c8b-4382-9126-e86bfef46ce6%22%2c%22Oid%22%3a%22df66b55b-8f64-4ec5-b277-382df506a6f5%22%7d)

### Build the source

```bash
mkdir build
cd build
cmake .. -DCMAKE_CXX_COMPILER=clang++
cmake --build . -- -j$(nproc)
```

### Run unit tests

```bash
cd build
./math_utils_test
```

### Run fuzz test and read crash dump

```bash
timeout 30 ./fuzz_math_utils || echo "Fuzz test crashed or timed out"
```

There are multiple ways to read the crashdump, I strongly recommend **hexdump**.

```bash
# read full crash dump
hexdump crash-123456789

# read crash dump and convert hex values to decimal
hexdump -v -e '"%d, "' -e '8/1 "0x%02x, " "\n"' crash-123456789
```

```bash
# read crash dump via xxd
xxd crash-123456789
```


```bash
# read crash dump via gdb and print the a,b values (partially)
gdb ./fuzz_math_utils
run < ./crash-123456789
print a
print b
```
