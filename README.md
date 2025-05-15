Mini Iceberg Engine
A lightweight C++ implementation inspired by Apache Iceberg's table format.

This project is a simplified engine that mimics the core concepts of the Apache Iceberg table format. It provides the ability to define schemas, append data, write metadata, and manage table manifests in a local environment using C++.

Features

    Create and manage named tables

    Define schemas with column names and types

    Append rows of data in memory

    Write data files and corresponding metadata to disk

    Read and reconstruct tables from metadata files

    JSON-based metadata handling for simplicity and readability

    Unit tests using Catch2

Goals

This project is meant for educational purposes to explore:

    Data engineering internals

    C++ design patterns (RAII, smart pointers)

    Filesystem and serialization in C++

    Preparation for more complex projects
