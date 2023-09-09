# BitcoinExchange

This first exercise is a Bitcoin currency calculator/interpreter, that takes an initial database and an input file and throws back the converted input accordingly.

## What is Bitcoin?

Bitcoin is a decentralized digital currency that was invented in 2008 by an individual or group using the pseudonym Satoshi Nakamoto. It was introduced as an open-source software project, and its main purpose was to provide an alternative to traditional government-issued currencies like the US dollar or the Euro.

One of the most remarkable aspects of Bitcoin is its price appreciation over time. Since its inception, Bitcoin's value has experienced significant fluctuations, but it has generally trended upward. In its early days, Bitcoin was virtually worthless, with its first recorded trading price being less than a cent. However, over the years, it has seen exponential growth in value, reaching thousands and eventually tens of thousands of dollars per Bitcoin.

## How does `btc` work?

In the root repository of the program, there must be a database file `data.csv`, from where the currency of a single bitcoin over time will be loaded into the program as a `std::map`. The database file must respect some ground rules:

- Columns must be separated by a single comma (`,`);

- There must be a header line with the columns `date` and `exchange_rate` described;

- Every line must be correctly filled, no extra columns or information missing;

- The `date` column must contain valid `YYYY-MM-DD` date strings;

- The `exchange_rate` column must contain only positive float numbers or integers.

There's no need to pass the database as a parameter to the program. As long as the file is correctly named and placed within the correct folder, the program will have no problem loading it in.

Next is the `input` file. It can have any name or extension, as long as its content is correctly formatted. The file will be passed as parameter to the program, which will then attempt to parse it.

- Columns must be separated by a single pipe (`|`);

- There must be a header line with the columns `date` and `value` described;

- The rest of the file doesn't necessarily need to be filled or correct. The parser will iterate through each line and process them individually.

- The `date` column must contain valid `YYYY-MM-DD` date strings, otherwise there will be an error described;

- The `value` column must contain only positive float numbers or integers, otherwise there will also be an error described;

- The converted currency will only be shown if the input is correct.

For each correct line parsed, the program will attempt to find the exchange rate for a single Bitcoin in the specified time. To do that, it will use the `std::map` methods, and attempt to reach the correct date.

If that specific date is not found, then the program will get the exchange rate for the closest previous date on the dictionary. If the date on the input is older than the first occurrence on the database, an Error will be thrown.

At the end, all lines in the input must be parsed and described in the standard output terminal with either the value correctly converted, or the error generated.

## Why use the `std::map` container?

### 1. Ordered Data Structure

`std::map` is an associative container that maintains its elements in a sorted order based on the keys. In the loaded database, the `date` is a critical piece of information, and having the data sorted by it simplifies various operations, including searching for specific dates or performing range-based queries. This ordered structure ensures efficient and accurate retrieval of exchange rates for specific dates.

### 2. Key-Value Pairing

Each entry in the BitcoinExchange database consists of two components: the `date` (**key**) and the corresponding `exchange rate` (**value**). `std::map` is a key-value container that perfectly fits this data structure, allowing the program to associate dates with their respective exchange rates easily. This key-value pairing simplifies data retrieval, insertion, and modification.

### 3. Logarithmic Time Complexity

`std::map` employs a self-balancing binary search tree (usually a Red-Black Tree) to store its elements. This choice of data structure results in logarithmic time complexity (`O(log n)`) for insertion, deletion, and search operations. This is especially advantageous when dealing with large datasets, as it ensures efficient data management and retrieval.

### 4. Unique Keys

`std::map` enforces uniqueness of keys by design. In the BitcoinExchange database, it's essential to have a unique date for each exchange rate entry. Using `std::map` guarantees that date won't be inadvertently duplicated, maintaining the integrity and accuracy of the data.
