# String index data structures

Implementation of string indexing data structures: trie, radix\_tree and ternary\_search\_tree.

## Data generation

The datasets used for testing are created using the following command

```
./generate_baseline_data <search_path>
```

which receives the search path from which files are chosen. Baseline datasets capture files with four types of extensions: .pdf, .mp3, .jpg and .cpp. These files are saved in data/data and can then be given as input to the executable that tests the trie.

## Testing

Given an already build dataset of filenames, one can search through the files by calling

```
./bin/partial_match <dataset_path> <index_structure>
```

which opens up an interface that receives filename queries and returns the path of name matches. Supported index structures are trie, radix\_tree and ternary\_search\_tree. Make sure you run `make` to be able to run the executables.
