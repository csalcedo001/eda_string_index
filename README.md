# Trie

Implementation of Trie data structure.

## Data generation

The datasets used for testing are created using the following command

```
./generate_baseline_data <search_path>
```

which receives the search path from which files are chosen. Baseline datasets capture files with four types of extensions: .pdf, .mp3, .jpg and .cpp. These can then be given as input to the executable that tests the trie.

## Testing

Given an already build dataset of filenames, one can search through the files by calling

```
./bin/file <dataset_path>
```

which opens up an interface that receives filename queries and returns the path of name matches. Make sure you run `make` to be able to run the executables.
