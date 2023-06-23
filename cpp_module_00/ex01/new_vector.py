import sys
import math
import numpy as np

def rotate_vector(normal, angles):
    # Convert angles from degrees to radians
    angles = [math.radians(angle) for angle in angles]

    # Create rotation matrices for each axis
    x_rotation = np.array([[1, 0, 0],
                           [0, math.cos(angles[0]), -math.sin(angles[0])],
                           [0, math.sin(angles[0]), math.cos(angles[0])]])

    y_rotation = np.array([[math.cos(angles[1]), 0, math.sin(angles[1])],
                           [0, 1, 0],
                           [-math.sin(angles[1]), 0, math.cos(angles[1])]])

    z_rotation = np.array([[math.cos(angles[2]), -math.sin(angles[2]), 0],
                           [math.sin(angles[2]), math.cos(angles[2]), 0],
                           [0, 0, 1]])

    # Apply rotations to the normal vector
    rotated_normal = np.dot(z_rotation, np.dot(y_rotation, np.dot(x_rotation, normal)))

    # Normalize the resulting vector
    normalized_normal = rotated_normal / np.linalg.norm(rotated_normal)

    return normalized_normal

if __name__ == "__main__":
    # Extract rotation angles from command-line arguments
    angles = [float(angle) for angle in sys.argv[1:]]

    # Check if three angles are provided
    if len(angles) != 3:
        print("Error: Please provide three rotation angles (x, y, z) in degrees.")
    else:
        # Define the initial normal vector
        normal = np.array([0.0, 1.0, 0.0])

        # Calculate the new normalized normal vector
        new_normal = rotate_vector(normal, angles)

        # Print the new normal vector
        print(new_normal)