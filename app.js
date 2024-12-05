const express = require("express");
const path = require("path");

const app = express();
const PORT = 3000;


app.get("/:name", (req, res) => {
  const filePath = path.join(__dirname, "files", `${req.params.name}.cpp`); // Path to your file
  res.download(filePath, `${req.params.name}.CPP`, (err) => {
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
