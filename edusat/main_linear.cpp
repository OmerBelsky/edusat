#include "LinearRegressionModel.h"

int main() {
    LinearRegressionModel model;

    // Load the trained model from file
    if (!model.loadModel("lr_model.txt")) {
        return 1; // Exit if loading fails
    }

    // Example feature vector
    std::vector<double> sample_features = { 0.5, 2.0, 1.5 }; // Example input features

    // Make a prediction
    double prediction = model.predict(sample_features);
    std::cout << "Predicted value: " << prediction << std::endl;

    // Example: Writing data to a CSV
    std::vector<int> indices = { 1, 2, 3, 4 };
    std::vector<double> data = { 1.2, 3.4, 5.6, 7.8 };
    model.writeVectorToCSV(indices, data);

    return 0;
}
