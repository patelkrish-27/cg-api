const express = require("express");
const path = require("path");

const app = express();
const PORT = 3000;

// Endpoint to download a file
app.get("/cohen", (req, res) => {
  const filePath = path.join(__dirname, "files", "COHEN.CPP"); // Path to your file
  res.download(filePath, "COHEN.CPP", (err) => {
    if (err) {
      console.error("Error while sending the file:", err);
      res.status(500).send("Error downloading the file");
    }
  });
});

app.get("/dda", (req, res) => {
  const filePath = path.join(__dirname, "files", "DDA.CPP"); // Path to your file
  res.download(filePath, "COHEN.CPP", (err) => {
    if (err) {
      console.error("Error while sending the file:", err);
      res.status(500).send("Error downloading the file");
    }
  });
});

app.get("/bresen", (req, res) => {
  const filePath = path.join(__dirname, "files", "BRESENHAM.CPP"); // Path to your file
  res.download(filePath, "COHEN.CPP", (err) => {
    if (err) {
      console.error("Error while sending the file:", err);
      res.status(500).send("Error downloading the file");
    }
  });
});

// Start the server
app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
