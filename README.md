# FDF: Wireframe Model

A 3D wireframe renderer in C: it reads `.fdf` height maps, projects them in isometric view, and draws the mesh with anti-aliased lines and a height-based color gradient.

## Features

- Parses `.fdf` grids (integers per cell; optional `height,0xRRGGBB` color suffix validated on load).
- Isometric-style projection and interactive window.
- **Xiaolin Wu** line drawing for smoother edges.
- **Height gradient**: low altitude → purple, high → blue (per-edge interpolation).
- **Cross-platform build**: Linux uses **MiniLibX** (`mlx_linux`); macOS uses **MLX42** (`mlx_macos`) with GLFW.
- **Rotation**: horizontal (yaw) and vertical (pitch) from original map coords.
- **Reset view** (`R`) plus zoom clamps so the model stays usable while testing.
- **Vim-style map switch** (`:` / `o`): type a name from `maps/`, Tab-complete, Enter to load without restarting.
- **Color schemes** (`C`): cycle height-gradient palettes.
- Map validation: rectangular grids, sensible error messages on bad input.
- Full-frame clear before first draw so the background is solid (no grey “empty” pixels on macOS).

## Prerequisites

The `Makefile` expects MLX next to this repo:

- `../mlx_linux` — Linux MiniLibX (with `libmlx` and X11 dev packages).
- `../mlx_macos` — MLX42 clone with a built static library at `build/libmlx42.a` (see that project’s README).

**macOS additionally:** install GLFW so the linker can find it, for example:

```bash
brew install glfw
```

The Makefile uses `-L/opt/homebrew/lib` and `-L/usr/local/lib` for `libglfw`.

## Build

```bash
cd fdf
make
```

Use `make re` for a clean rebuild.

## Usage

```bash
./fdf path/to/map.fdf
```

Bundled examples:

```bash
./fdf maps/42.fdf      # classic 42 subject map (digits “42” in height)
./fdf maps/pyramid.fdf
./fdf maps/waves.fdf
./fdf maps/mars.fdf
```

Each row is a line of space-separated values; row length must be consistent. The file’s horizontal index is X, line number is Y, and the value is Z (altitude).

## Controls

| Input | Action |
|--------|--------|
| **W** / **A** / **S** / **D** | Pan the model (up / left / down / right). |
| **←** / **→** | Rotate horizontally (yaw). |
| **Q** / **E** | Rotate vertically (pitch). |
| **↑** / **↓** | Zoom in / out around the **center** of the window (×2 / ÷2). |
| **Mouse wheel** | Zoom in / out toward the **cursor** (~1.1× per notch; clamped). On Linux: wheel buttons **4** / **5**. |
| **R** | Reset view (angles, zoom, and position). |
| **C** | Cycle color scheme (purple-blue → white → green-cyan → red-gold → grey-white). |
| **:** or **o** | Open command line (vim-style). Type a map stem (`mars`, `42`, …) or `e` to reload; names resolve under `maps/`. |
| **Tab** (in command mode) | Complete / list matching `.fdf` files in `maps/`. |
| **Enter** (in command mode) | Load the map and reset the view. |
| **Escape** | Cancel command mode, or quit if not in command mode. |
| **Window close** | Quit. |

## Technical notes

- **Languages / libs:** C, custom **libft**, `-lm`, platform MLX as above.
- **macOS pixels:** MLX42 uses **RGBA** byte order in the image buffer; the renderer writes R,G,B,A explicitly so colors and clears match OpenGL.
- **Parsing:** Uses libft (`get_next_line`, `split`, etc.) with checks for empty maps, bad tokens, and non-rectangular rows.

## Future ideas

- Mouse-drag rotation.
- Other projections, optional flat shading.

## Context

Project developed in the context of **42** school graphics introduction (FDF / fil de fer).

## Acknowledgments

Thanks to the 42 curriculum and the MiniLibX / MLX42 ecosystems used for windowing and drawing.
