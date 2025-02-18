//
// Created by kx on 2023/1/4.
//

#ifndef BATTLE_GAME_KIRIMA_KOKONA_H
#define BATTLE_GAME_KIRIMA_KOKONA_H

#pragma once
#include "battle_game/core/unit.h"

namespace battle_game::unit {
class kx_Tank : public Unit {
 public:
  kx_Tank(GameCore *game_core, uint32_t id, uint32_t player_id);
  void Render() override;
  void Update() override;
  [[nodiscard]] bool IsHit(glm::vec2 position) const override;

 protected:
  void TankMove(float move_speed, float rotate_angular_speed);
  void TurretRotate();
  void Fire();
  [[nodiscard]] const char *UnitName() const override;
  [[nodiscard]] const char *Author() const override;

  float turret_rotation_{0.0f};
  uint32_t fire_count_down_{0};
  bool is_stuck_by_swamp{false};
};
}

#endif  // BATTLE_GAME_KIRIMA_KOKONA_H
