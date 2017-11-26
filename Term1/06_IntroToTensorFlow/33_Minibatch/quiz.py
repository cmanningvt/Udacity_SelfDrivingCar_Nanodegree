import math
def batches(batch_size, features, labels):
    """
    Create batches of features and labels
    :param batch_size: The batch size
    :param features: List of features
    :param labels: List of labels
    :return: Batches of (Features, Labels)
    """
    assert len(features) == len(labels)
    # TODO: Implement batching
    batches = []

    for n in range(0, len(features), batch_size):
        batches.append([features[n:n+batch_size], labels[n:n+batch_size]])

    return batches