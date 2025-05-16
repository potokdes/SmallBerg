Mini Iceberg Engine
A lightweight C++ implementation inspired by Apache Iceberg's table format.

This project is a simplified engine that mimics the core concepts of the Apache Iceberg table format. It provides the ability to define schemas, append data, write metadata, and manage table manifests in a local environment using C++.

Features

    Road map:
    1. Row object	Introduce a Row class -- 
    2. Data typing	Add real data types to Row	--
    3. File I/O	Serialize/deserialize tables	--
    4. Table metadata	Store metadata in manifest files	--
    5. Partitioning	Add basic partition support	PartitionSpec, file grouping --
    6. Schema evolution	Support schema updates	versioned schemas, column IDs --
    7. Transaction log	Simulate table snapshots	Manifest list, snapshot IDs --
    8. Multi-threading	Parallel read/write	std::future, thread, locks --
    9. Query API	Build a simple query interface	Filters, projections -- 
    10. Optimizations	File pruning, caching	Indexing, metadata skipping --

Goals

This project is meant for educational purposes to explore:

    Data engineering internals

    C++ design patterns (RAII, smart pointers)

    Filesystem and serialization in C++

    Preparation for more complex projects

## Domain Model Concepts

This project is a minimal C++ implementation inspired by Apache Iceberg, focused on learning modern C++ through real-world data engineering concepts. The core domain objects are:

###  Table

The main abstraction representing a logical table. It encapsulates operations on the table, such as inserting rows, managing schema, and accessing metadata. This class hides the complexity of low-level storage and schema handling.

###  Schema

A schema defines the structure of a table by describing its columns. It validates incoming data against column definitions and supports basic schema evolution features. Each schema is uniquely identified by a schema ID.

###  Column

Represents a single field within a schema. A column contains a `name` and a `data type`, forming the building blocks of schema definitions. It is the smallest unit of structural metadata in the model.
