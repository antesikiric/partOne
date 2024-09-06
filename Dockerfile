# Step 1: Use an official C++ image with build tools
FROM gcc:latest

# Step 2: Install curl and other dependencies
RUN apt-get update && apt-get install -y \
    libcurl4-openssl-dev \
    cmake \
    make \
    && rm -rf /var/lib/apt/lists/*

# Step 3: Set the working directory in the container
WORKDIR /app

# Step 4: Copy the current directory contents into the container at /app
COPY . .

# Step 5: Compile the C++ program
RUN g++ main.cpp HashTable.cpp downloader.cpp utils.cpp -lcurl -o program

# Step 6: Run the compiled binary (optional)
CMD ["./program"]

