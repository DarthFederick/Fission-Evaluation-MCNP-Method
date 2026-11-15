# Fission-Evaluation-MCNP-Method
A from-scratch Monte Carlo neutron transport and criticality (k-eff) solver written in C, validated against standard nuclear reactor benchmarks, progressing from bare critical assemblies (Godiva) to heterogeneous reactor cores.

## Development Roadmap & Validation
\
### Milestone 1: Pure Neutron Transport (Scattering & Absorption) — Completed
Implemented the core 3D continuous-space Monte Carlo transport engine in C (`gnu11`) for a homogeneous spherical geometry modeled after the bare enriched-uranium **Godiva** benchmark ($R = 8.7407\text{ cm}$, $\Sigma_t = 0.277415\text{ cm}^{-1}$, $\Sigma_s = 0.210835\text{ cm}^{-1}$).

**Key Features Implemented:**
* **Modular Architecture:** Separated 3D vector algebra (`vectors`), particle/geometry definitions (`objects`), and stochastic transport physics (`neutron_functions`) with an automated `Makefile` build pipeline.
* **Stochastic Sampling:** Exponential free-path sampling ($s = -\ln(1-\xi)/\Sigma_t$) and isotropic direction sampling over $4\pi$ ($\mu \in [-1, 1]$, $\phi \in [0, 2\pi)$) using the 48-bit POSIX linear congruential generator (`drand48`).
* **Tracking & Reaction Channels:** Event-driven particle history loop handling geometric boundary escape ($r > R$) and competitive collision sampling between isotropic scattering ($p_s = \Sigma_s / \Sigma_t$) and radiative capture/absorption.

**Benchmark Validation ($N = 100{,}000$ histories, central isotropic source):**
* **Particle Conservation:** $100\%$ verified ($N_{\text{absorbed}} + N_{\text{escaped}} = N$)
* **Absorbed Fraction:** `60.37%` ($60{,}367$ neutrons)
* **Escaped Fraction:** `39.63%` ($39{,}633$ neutrons)
* Results match the theoretical spherical transport expectation ($\approx 60.37\%$ absorbed / $39.63\%$ escaped) within the expected binomial statistical uncertainty ($\sigma \approx 0.15\%$).

### Next Steps (Milestone 2)
* Incorporate the macroscopic fission cross-section ($\Sigma_f$) and average neutron multiplicity ($\bar{\nu}$) into the reaction channel sampling.
* Implement generational fission-bank storage and the power iteration method to evaluate the effective multiplication factor ($k_{\text{eff}}$) of the critical assembly.
