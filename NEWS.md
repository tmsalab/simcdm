# simcdm 0.0.5

- Added _C++_ and _R_ functions for simulation of:
    - Deterministic Input, Noisy "And" Gate (DINA)
        - Item Response: `sim_dina_items()`
        - $\eta$ Response: `sim_dina_attributes()`.
    - reduced Reparameterized Unified Model (rRUM):
        - Item Reponse: `sim_rrum_items()`
    - Matrices:
        - Random Q Matrix: `sim_q_matrix()`
        - ETA Matrix: `sim_eta_matrix()`
        - Latent Attribute Profile Matrix: `sim_attribute_classes()`
        - Latent Attribute Profiles for Subjects: `sim_subject_attributes()`
