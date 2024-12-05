const express = require("express");
const path = require("path");
const fs = require("fs");

const app = express();
const PORT = 3000;

app.get("/:name", (req, res) => {
  const directoryPath = path.join(__dirname, "files"); // Path to your directory
  const requestedFileName = req.params.name; // The name provided in the URL

  // Read all files in the directory
  fs.readdir(directoryPath, (err, files) => {
    if (err) {
      console.error("Error reading directory:", err);
      return res.status(500).send("Server error");
    }

    // Find a file with a matching name (case-insensitive)
    const matchedFile = files.find(
      (file) => file.toLowerCase() === `${requestedFileName.toLowerCase()}.cpp`
    );

    if (matchedFile) {
      const filePath = path.join(directoryPath, matchedFile);

      // Send the matched file as a download
      res.download(filePath, matchedFile, (err) => {
        if (err) {
          console.error("Error while sending the file:", err);
          res.status(500).send("Error downloading the file");
        }
      });
    } else {
      // If no matching file is found
      res.status(404).send("File not found");
    }
  });
});

// Start the server
app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
