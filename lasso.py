import numpy as np
import pandas as pd


def fit(X, y):
    (n_observations, n_features) = X.shape
    (y_len,) = y.shape

    if n_observations != y_len:
        msg = "y must be the same lengeth as the number of rows in X"
        raise ValueError(msg)

    weights = np.random.randn(n_features) / np.sqrt(n_features)
    learning_rate = 0.001
    momentum = 0.9
    velocity = 0.9

    tol = 0.0001
    old_mse = None

    for i in range(1000):
        y_pred = X.dot(weights)
        delta = y_pred - y
        gradient = X.T.dot(delta)
        # velocity = momentum * velocity - learning_rate * gradient
        # weights += velocity
        weights = weights - learning_rate * gradient
        #learning_rate /= 2 # decay
        if old_mse is None:
            mse = delta.dot(delta) / n_observations
            old_mse = mse
        else:
            old_mse = mse
            mse = delta.dot(delta) / n_observations
            diff = np.abs(mse - old_mse)
            if diff < tol:
                print(f"converged after {i} iterations")
                return weights, mse
    print(f"failed to converg after {i} iterations")
    return weights, mse


n_observations = 50
n_features = 50

X = (np.random.random((n_observations, n_features)) - 0.5) * 10
w_dash = np.array([1, 0.5, -0.5] + [0] * (n_features - 3))
y = X.dot(w_dash) + np.random.randn(n_observations) * 0.5

weights, mse = fit(X, y)
print("mse =", mse)

# df = pd.read_csv("asec_csv_repwgt_2020.csv")
# cols = [f"pwwgt{i}" for i in range(161)]
# y = df["PPPOS"]
# X = df[cols].to_numpy()
# weights = fit(X, y)
# print("final weights:", weights)
