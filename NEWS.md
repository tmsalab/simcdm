# simcdm 0.1.0

## Changes

- Renamed `sim_attribute_classes()` to `attribute_classes()`.

## Deployment

- Added Unit Tests to verify simulation routines and attribute generations.

# simcdm 0.0.5

## Features

- Added _C++_ and _R_ functions for simulation of:
    - Deterministic Input, Noisy "And" Gate (DINA)
        - Item Response: `sim_dina_items()`
        - $\eta$ Response: `sim_dina_attributes()`.
    - reduced Reparameterized Unified Model (rRUM):
        - Item Reponse: `sim_rrum_items()`
    - Matrices:
        - Random Q Matrix: `sim_q_matrix()`
        - ETA Matrix: `sim_eta_matrix()`
        - Latent Attribute Profiles for Subjects: `sim_subject_attributes()`
    - Attributes:
        - Latent Attribute Profile Matrix: `sim_attribute_classes()`
        - Attribute Bijection: `attribute_bijection()`
        - Attribute Inverse Bijection: `attribute_inv_bijection()`